"""Download and install ISPA libraries from GitHub, archives, or a YAML catalog."""

import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess
import sys
import tarfile
import tempfile
from urllib.parse import quote, urlparse
from urllib.request import Request, urlopen
import zipfile

import yaml


CATALOG_URL = "https://raw.githubusercontent.com/Sinfolke/ispa-parser-generator/main/ispa-libraries.yaml"
DEFAULT_CATALOG = {"packages": {"std": {"github": "Sinfolke/ispa-parser-generator", "ref": "main"}}}
FOLDERS = ("ispalib", "ispatarget", "ispaalgorithm")
GITHUB = re.compile(r"^[\w.-]+/[\w.-]+$")
NAME = re.compile(r"^[A-Za-z0-9][A-Za-z0-9._-]*$")


def default_root():
    if os.environ.get("ISPA_PKG_ROOT"):
        return Path(os.environ["ISPA_PKG_ROOT"])
    if os.environ.get("ISPA_INSTALL_DIR"):
        return Path(os.environ["ISPA_INSTALL_DIR"]) / "libraries"
    # Nuitka onefile keeps the original executable location in argv[0].
    for executable_name in (sys.argv[0], sys.executable):
        executable = Path(executable_name).resolve()
        if executable.parent.parent.name == "versions":
            return executable.parent.parent.parent / "libraries"
    if os.name == "nt" and os.environ.get("LOCALAPPDATA"):
        return Path(os.environ["LOCALAPPDATA"]) / "Programs" / "ISPA" / "libraries"
    if os.environ.get("XDG_DATA_HOME"):
        return Path(os.environ["XDG_DATA_HOME"]) / "ispa" / "libraries"
    return Path.home() / ".local" / "share" / "ispa" / "libraries"


class PackageError(Exception):
    pass


def read_yaml(data, label):
    try:
        parsed = yaml.safe_load(data) or {}
    except yaml.YAMLError as error:
        raise PackageError(f"Invalid YAML in {label}: {error}") from error
    if not isinstance(parsed, dict):
        raise PackageError(f"{label} must contain a YAML mapping")
    return parsed


def safe_relative(value):
    if not isinstance(value, str) or not value or "\\" in value:
        raise PackageError(f"Invalid relative path: {value!r}")
    path = PurePosixPath(value)
    if path.is_absolute() or any(part in ("..", ".") for part in value.split("/")) or ":" in path.parts[0]:
        raise PackageError(f"Unsafe relative path: {value!r}")
    return Path(*path.parts)


def request(url):
    try:
        with urlopen(Request(url, headers={"User-Agent": "ispa-pkg", "Accept": "application/vnd.github+json"}), timeout=30) as response:
            return response.read()
    except Exception as error:
        raise PackageError(f"Cannot download {url}: {error}") from error


def fetch_file(location, base=None):
    if location.startswith(("https://", "http://")):
        return request(location)
    path = Path(location)
    if not path.is_absolute() and base is not None:
        path = base / safe_relative(location)
    return path.read_bytes()


def unpack(data, name, destination):
    destination.mkdir(parents=True, exist_ok=True)
    archive = destination / "archive"
    archive.write_bytes(data)
    destination = destination / "content"
    destination.mkdir()

    def valid(name):
        while name.startswith("./"):
            name = name[2:]
        if name.endswith("/"):
            name = name[:-1]
        if not name or name == ".":
            return None
        return safe_relative(name)

    if name.endswith(".zip"):
        with zipfile.ZipFile(archive) as src:
            for entry in src.infolist():
                relative = valid(entry.filename)
                if relative is None:
                    continue
                target = destination / relative
                mode = entry.external_attr >> 16
                if (mode & 0o170000) == 0o120000:
                    raise PackageError(f"Symlink in archive: {entry.filename}")
                if entry.is_dir():
                    target.mkdir(parents=True, exist_ok=True)
                else:
                    target.parent.mkdir(parents=True, exist_ok=True)
                    target.write_bytes(src.read(entry))
    elif name.endswith((".tar.gz", ".tgz")):
        with tarfile.open(archive, "r:gz") as src:
            for entry in src:
                relative = valid(entry.name)
                if relative is None:
                    continue
                target = destination / relative
                if entry.isdir():
                    target.mkdir(parents=True, exist_ok=True)
                elif entry.isfile():
                    target.parent.mkdir(parents=True, exist_ok=True)
                    with src.extractfile(entry) as stream, target.open("wb") as output:
                        shutil.copyfileobj(stream, output)
                else:
                    raise PackageError(f"Unsupported archive member: {entry.name}")
    else:
        raise PackageError("Archive must end in .zip, .tar.gz, or .tgz")
    children = list(destination.iterdir())
    return children[0] if len(children) == 1 and children[0].is_dir() else destination


def github_source(repo, ref, workspace):
    if not GITHUB.fullmatch(repo):
        raise PackageError(f"Invalid GitHub repository: {repo}")
    sha = json.loads(request(f"https://api.github.com/repos/{repo}/commits/{quote(ref, safe='')}"))["sha"]
    data = request(f"https://api.github.com/repos/{repo}/tarball/{sha}")
    return unpack(data, "source.tar.gz", workspace), sha


def source_tree(spec, workspace):
    if "github" in spec:
        return github_source(spec["github"], spec.get("ref", "main"), workspace)
    if "archive" in spec:
        location = spec["archive"]
        data = fetch_file(location)
        return unpack(data, urlparse(location).path, workspace), hashlib.sha256(data).hexdigest()
    if "path" in spec:
        path = Path(spec["path"]).expanduser().resolve()
        if not path.is_dir():
            raise PackageError(f"Directory not found: {path}")
        return path, "local"
    raise PackageError("Package source must have github, archive, or path")


def layout_entries(config):
    layout = config.get("layout", {})
    if not isinstance(layout, dict):
        raise PackageError("layout must be a mapping")
    result = []
    for folder in FOLDERS:
        mapping = layout.get(folder)
        if mapping is None:
            defaults = {"ispalib": ("grammar", "python"), "ispatarget": (), "ispaalgorithm": ()}
            mapping = {name: f"{folder}/{name}" for name in defaults[folder]}
            if folder == "ispatarget":
                mapping = {"cpp": "ispatarget/cpp", "python": "ispatarget/python"}
            if folder == "ispaalgorithm":
                mapping = {".": "ispaalgorithm"}
        if not isinstance(mapping, dict):
            raise PackageError(f"layout.{folder} must be a mapping")
        for name, source in mapping.items():
            if not isinstance(name, str) or not isinstance(source, str):
                raise PackageError(f"Invalid layout.{folder} entry")
            dest = Path(folder) if name == "." else Path(folder) / safe_relative(name)
            result.append((safe_relative(source), dest))
    files = layout.get("files", {})
    if not isinstance(files, dict):
        raise PackageError("layout.files must be a mapping")
    file_entries = [(safe_relative(source), safe_relative(dest)) for dest, source in files.items()]
    root = safe_relative(layout.get("root", ".")) if layout.get("root", ".") != "." else Path(".")
    return root, result, file_entries


def install(name, spec, root, allow_scripts=False, force=False, from_catalog=False):
    if not NAME.fullmatch(name):
        raise PackageError(f"Invalid package name: {name}")
    root.mkdir(parents=True, exist_ok=True)
    target = root / name
    with tempfile.TemporaryDirectory(prefix=".ispa-pkg-", dir=root) as temp:
        work = Path(temp)
        tree, revision = source_tree(spec, work)
        config_tree = tree
        config_file = tree / "ispa-package.yaml"
        config = read_yaml(config_file.read_text(encoding="utf-8"), str(config_file)) if config_file.is_file() else {}
        if "archive" in config:
            location = config["archive"]
            data = fetch_file(location, tree)
            nested = work / "nested"
            nested.mkdir()
            tree = unpack(data, urlparse(location).path, nested)
            revision += ":" + hashlib.sha256(data).hexdigest()
        root_path, entries, file_entries = layout_entries(config)
        source_root = tree / root_path
        if not source_root.is_dir():
            raise PackageError(f"Layout root not found: {root_path}")
        scripts = config.get("install", [])
        if isinstance(scripts, str):
            scripts = [scripts]
        if not isinstance(scripts, list) or any(not isinstance(item, str) for item in scripts):
            raise PackageError("install must be a list of script paths")
        if "path" in spec:
            digest = hashlib.sha256()
            inputs = [source_root / src for src, _ in entries] + [source_root / src for src, _ in file_entries]
            inputs += [config_tree / safe_relative(script) for script in scripts]
            for origin in inputs:
                if origin.is_symlink():
                    raise PackageError(f"Symlink in library: {origin}")
                if origin.is_file():
                    files = [origin]
                elif origin.is_dir():
                    members = list(origin.rglob("*"))
                    for member in members:
                        if member.is_symlink():
                            raise PackageError(f"Symlink in library: {member}")
                    files = sorted(file for file in members if file.is_file())
                else:
                    continue
                for file in files:
                    if file.is_symlink():
                        raise PackageError(f"Symlink in library: {file}")
                    try:
                        relative = file.relative_to(source_root)
                        digest.update(b"library/")
                    except ValueError:
                        relative = file.relative_to(config_tree)
                        digest.update(b"repository/")
                    digest.update(relative.as_posix().encode())
                    digest.update(file.read_bytes())
            revision = digest.hexdigest()
        fingerprint = hashlib.sha256(json.dumps({"spec": spec, "revision": revision, "config": config,
                                                "from_catalog": from_catalog}, sort_keys=True).encode()).hexdigest()
        marker = target / ".ispa-package.json"
        if marker.is_file() and not force:
            try:
                if json.loads(marker.read_text())["fingerprint"] == fingerprint:
                    print(f"{name}: up to date ({revision[:12]})")
                    return
            except (ValueError, KeyError):
                pass
        if scripts and not allow_scripts:
            raise PackageError(f"{name} declares install scripts; rerun with --allow-scripts to execute them")
        stage = work / "stage"
        stage.mkdir()
        copied = 0
        for src, dest in entries:
            origin = source_root / src
            if origin.is_symlink():
                raise PackageError(f"Symlink in library: {origin}")
            if not origin.is_dir():
                continue
            destination = stage / dest
            shutil.copytree(origin, destination, symlinks=False, dirs_exist_ok=True)
            copied += 1
        for src, dest in file_entries:
            origin = source_root / src
            if not origin.is_file() or origin.is_symlink():
                raise PackageError(f"Layout file not found: {src}")
            destination = stage / dest
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(origin, destination)
            copied += 1
        if not copied:
            raise PackageError(f"No library folders found in {source_root}")
        for script in scripts:
            script_path = config_tree / safe_relative(script)
            if not script_path.is_file() or script_path.is_symlink():
                raise PackageError(f"Install script not found: {script}")
            if script_path.suffix == ".py":
                command = [sys.executable, str(script_path), str(stage)]
            elif os.name == "nt":
                raise PackageError("Shell install scripts require a POSIX shell")
            else:
                command = ["sh", str(script_path), str(stage)]
            subprocess.run(command, cwd=config_tree, check=True)
        marker_data = {"name": name, "source": spec, "revision": revision, "fingerprint": fingerprint,
                       "from_catalog": from_catalog}
        (stage / ".ispa-package.json").write_text(json.dumps(marker_data, indent=2) + "\n")
        backup = work / "previous"
        if target.exists():
            target.rename(backup)
        try:
            stage.rename(target)
        except Exception:
            if backup.exists():
                backup.rename(target)
            raise
        print(f"{name}: installed ({revision[:12]}) at {target}")


def catalog(root, path=None):
    path = Path(path) if path else root / "catalog.yaml"
    return read_yaml(path.read_text(encoding="utf-8"), str(path)) if path.is_file() else DEFAULT_CATALOG


def parse_source(value):
    if value.startswith("https://github.com/"):
        value = value.removeprefix("https://github.com/").removesuffix(".git").rstrip("/")
    if Path(value).is_dir():
        return {"path": str(Path(value).resolve())}
    if GITHUB.fullmatch(value):
        return {"github": value, "ref": "main"}
    if value.endswith((".zip", ".tar.gz", ".tgz")):
        return {"archive": value}
    raise PackageError(f"Unknown package or source: {value}")


def main(argv=None):
    parser = argparse.ArgumentParser(prog="ispa-pkg", description=__doc__)
    parser.add_argument("--root", type=Path, default=default_root())
    parser.add_argument("--catalog", type=Path, help="Local YAML catalog path")
    sub = parser.add_subparsers(dest="command", required=True)
    add = sub.add_parser("install", help="Install a catalog name, GitHub repository, or archive")
    add.add_argument("source")
    add.add_argument("--name", help="Installed name for a direct source")
    add.add_argument("--ref", help="GitHub branch, tag, or commit")
    add.add_argument("--allow-scripts", action="store_true")
    add.add_argument("--force", action="store_true")
    update = sub.add_parser("update", help="Update installed packages")
    update.add_argument("names", nargs="*")
    update.add_argument("--allow-scripts", action="store_true")
    sub.add_parser("list", help="List installed packages")
    catalog_cmd = sub.add_parser("catalog", help="Manage the YAML catalog")
    catalog_cmd.add_argument("action", choices=["update", "list"])
    catalog_cmd.add_argument("--url", default=CATALOG_URL, help="GitHub raw YAML URL")
    args = parser.parse_args(argv)
    root = args.root.expanduser().resolve()
    try:
        if args.command == "catalog":
            if args.action == "update":
                if not args.url.startswith("https://"):
                    raise PackageError("Catalog URL must use HTTPS")
                data = request(args.url)
                parsed = read_yaml(data, args.url)
                if not isinstance(parsed.get("packages"), dict):
                    raise PackageError("Catalog must contain a packages mapping")
                path = args.catalog or root / "catalog.yaml"
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(data)
                print(f"Updated catalog: {path}")
            else:
                for name in catalog(root, args.catalog).get("packages", {}):
                    print(name)
        elif args.command == "list":
            for marker in sorted(root.glob("*/.ispa-package.json")):
                data = json.loads(marker.read_text())
                print(f"{data['name']}\t{data['revision'][:12]}\t{marker.parent}")
        elif args.command == "install":
            packages = catalog(root, args.catalog).get("packages", {})
            spec = packages.get(args.source) if isinstance(packages, dict) else None
            spec = dict(spec) if isinstance(spec, dict) else parse_source(args.source)
            if args.ref:
                if "github" not in spec:
                    raise PackageError("--ref applies only to GitHub repositories")
                spec["ref"] = args.ref
            name = args.name or (args.source if args.source in packages else Path(args.source.rstrip("/")).name.removesuffix(".git").split(".")[0])
            install(name, spec, root, args.allow_scripts, args.force, args.source in packages)
        else:
            markers = list(root.glob("*/.ispa-package.json"))
            installed = {p.parent.name: json.loads(p.read_text()) for p in markers}
            names = args.names or sorted(installed)
            for name in names:
                if name not in installed:
                    raise PackageError(f"Package not installed: {name}")
                packages = catalog(root, args.catalog).get("packages", {})
                spec = packages.get(name, installed[name]["source"]) if installed[name].get("from_catalog") else installed[name]["source"]
                install(name, spec, root, args.allow_scripts, from_catalog=installed[name].get("from_catalog", False))
        return 0
    except (PackageError, OSError, ValueError, subprocess.CalledProcessError, zipfile.BadZipFile, tarfile.TarError) as error:
        print(f"ispa-pkg: {error}", file=sys.stderr)
        return 1


def run():
    raise SystemExit(main())
