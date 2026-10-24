import io
import json
from pathlib import Path
import tarfile
import tempfile
import unittest
import sys
import zipfile
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "cli" / "pkg"))
from ispa_pkg.cli import PackageError, default_root, install, main, unpack


class PackageTests(unittest.TestCase):
    def test_installed_executable_selects_installation_library_root(self):
        with tempfile.TemporaryDirectory() as temp:
            executable = Path(temp) / "versions" / "v1" / "ispa-pkg"
            with patch.dict("os.environ", {"ISPA_PKG_ROOT": "", "ISPA_INSTALL_DIR": ""}), \
                    patch("sys.executable", str(executable)):
                self.assertEqual(default_root(), Path(temp) / "libraries")

    def test_install_dir_override_selects_library_root(self):
        with tempfile.TemporaryDirectory() as temp:
            with patch.dict("os.environ", {"ISPA_PKG_ROOT": "", "ISPA_INSTALL_DIR": temp}):
                self.assertEqual(default_root(), Path(temp) / "libraries")

    def test_local_layout_and_revision(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            source = base / "source"
            (source / "release" / "grammar-renamed").mkdir(parents=True)
            (source / "release" / "grammar-renamed" / "hello.isc").write_text("first")
            (source / "ispa-package.yaml").write_text(
                "layout:\n  root: release\n  ispalib:\n    grammar: grammar-renamed\n"
            )
            root = base / "installed"
            install("example", {"path": str(source)}, root)
            result = root / "example" / "ispalib" / "grammar" / "hello.isc"
            self.assertEqual(result.read_text(), "first")
            revision = json.loads((root / "example" / ".ispa-package.json").read_text())["revision"]
            install("example", {"path": str(source)}, root)
            self.assertEqual(json.loads((root / "example" / ".ispa-package.json").read_text())["revision"], revision)
            (source / "release" / "grammar-renamed" / "hello.isc").write_text("second")
            install("example", {"path": str(source)}, root)
            self.assertEqual(result.read_text(), "second")

    def test_install_script_requires_opt_in(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            source = base / "source"
            (source / "ispalib" / "grammar").mkdir(parents=True)
            (source / "ispalib" / "grammar" / "x.isc").write_text("x")
            (source / "ispa-package.yaml").write_text("install: [build.py]\n")
            (source / "build.py").write_text("import pathlib, sys\n(pathlib.Path(sys.argv[1]) / 'built').write_text('yes')\n")
            with self.assertRaises(PackageError):
                install("example", {"path": str(source)}, base / "installed")
            install("example", {"path": str(source)}, base / "installed", allow_scripts=True)
            self.assertEqual((base / "installed" / "example" / "built").read_text(), "yes")

    def test_archive_rejects_traversal(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            buffer = io.BytesIO()
            with zipfile.ZipFile(buffer, "w") as archive:
                archive.writestr("../escape", "bad")
            with self.assertRaises(PackageError):
                unpack(buffer.getvalue(), "bad.zip", base / "zip")

            buffer = io.BytesIO()
            with tarfile.open(fileobj=buffer, mode="w:gz") as archive:
                info = tarfile.TarInfo("../escape")
                info.size = 3
                archive.addfile(info, io.BytesIO(b"bad"))
            with self.assertRaises(PackageError):
                unpack(buffer.getvalue(), "bad.tar.gz", base / "tar")

    def test_zip_archive_source(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            archive_path = base / "example.zip"
            with zipfile.ZipFile(archive_path, "w") as archive:
                archive.writestr("release/ispalib/grammar/module.isc", "module demo;")
            install("example", {"archive": str(archive_path)}, base / "installed")
            self.assertEqual(
                (base / "installed/example/ispalib/grammar/module.isc").read_text(),
                "module demo;",
            )

    def test_repository_config_can_select_nested_archive_and_file(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            source = base / "source"
            source.mkdir()
            with zipfile.ZipFile(source / "payload.zip", "w") as archive:
                archive.writestr("payload/grammar/module.isc", "module demo;")
                archive.writestr("payload/target/ispa_std.py", "name = 'std'\n")
            (source / "ispa-package.yaml").write_text(
                "archive: payload.zip\nlayout:\n  ispalib:\n    grammar: grammar\n"
                "  files:\n    ispatarget/ispa_std.py: target/ispa_std.py\n"
            )
            root = base / "installed"
            install("example", {"path": str(source)}, root)
            self.assertEqual((root / "example/ispatarget/ispa_std.py").read_text(), "name = 'std'\n")
            first = json.loads((root / "example/.ispa-package.json").read_text())["fingerprint"]
            install("example", {"path": str(source)}, root)
            self.assertEqual(json.loads((root / "example/.ispa-package.json").read_text())["fingerprint"], first)

    def test_update_keeps_direct_source_even_if_name_is_in_catalog(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            source = base / "source"
            (source / "ispalib/grammar").mkdir(parents=True)
            (source / "ispalib/grammar/x.isc").write_text("x")
            root = base / "installed"
            self.assertEqual(main(["--root", str(root), "install", str(source), "--name", "std"]), 0)
            self.assertEqual(main(["--root", str(root), "update", "std"]), 0)

    def test_github_commit_controls_update(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp) / "installed"
            commit = ["a" * 40]

            def fake_request(url):
                if "/commits/" in url:
                    return json.dumps({"sha": commit[0]}).encode()
                buffer = io.BytesIO()
                with tarfile.open(fileobj=buffer, mode="w:gz") as archive:
                    data = commit[0].encode()
                    info = tarfile.TarInfo("repo/ispalib/grammar/x.isc")
                    info.size = len(data)
                    archive.addfile(info, io.BytesIO(data))
                return buffer.getvalue()

            with patch("ispa_pkg.cli.request", side_effect=fake_request):
                spec = {"github": "owner/repo", "ref": "main"}
                install("example", spec, root)
                first = json.loads((root / "example/.ispa-package.json").read_text())["fingerprint"]
                install("example", spec, root)
                self.assertEqual(json.loads((root / "example/.ispa-package.json").read_text())["fingerprint"], first)
                commit[0] = "b" * 40
                install("example", spec, root)
                self.assertEqual((root / "example/ispalib/grammar/x.isc").read_text(), "b" * 40)


if __name__ == "__main__":
    unittest.main()
