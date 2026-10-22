plugins {
    kotlin("jvm") version "2.0.21"
    id("org.jetbrains.intellij.platform") version "2.2.1"
}

group = "dev.ispa"
version = "0.2.0"

repositories { mavenCentral(); intellijPlatform { defaultRepositories() } }

dependencies {
    intellijPlatform { intellijIdeaCommunity("2024.3.5") }
    testImplementation(kotlin("test-junit"))
}

kotlin { jvmToolchain(21) }

intellijPlatform {
    pluginConfiguration {
        ideaVersion { sinceBuild = "243"; untilBuild = provider { null } }
        changeNotes = "Support for extern parser imports and embedded Python syntax validation with the latest ISPA grammar."
    }
}

val bridgeBuild = layout.buildDirectory.dir("native-build")
val isWindowsHost = System.getProperty("os.name").lowercase().contains("windows")
val bridgeFileName = "ispa-grammar-bridge" + if (isWindowsHost) ".exe" else ""
val bridgeExecutable = bridgeBuild.map { it.file(bridgeFileName) }
val compileIspaBridge by tasks.registering(Exec::class) {
    inputs.files("CMakeLists.txt", "parser_bridge.cpp", "../../parser/CMakeLists.txt")
    inputs.files(fileTree("../../parser/ispa") { include("**/*.h", "**/*.hpp", "**/*.cpp") })
    inputs.files(fileTree("../../parser/python") { include("**/*.h", "**/*.hpp", "**/*.cpp") })
    inputs.files(fileTree("../../parser/stdlibs") { include("CMakeLists.txt", "**/*.h", "**/*.hpp", "**/*.cpp") })
    listOf("CC", "CXX", "CFLAGS", "CXXFLAGS", "LDFLAGS", "LD").forEach { key -> inputs.property(key, System.getenv(key) ?: "") }
    outputs.file(bridgeBuild.map { it.file("CMakeCache.txt") })
    doFirst {
        bridgeBuild.get().asFile.deleteRecursively()
        bridgeBuild.get().asFile.mkdirs()
    }
    commandLine("cmake", "-S", projectDir.absolutePath, "-B", bridgeBuild.get().asFile.absolutePath,
        "-DISPA_ROOT=${projectDir.parentFile.parentFile.absolutePath}")
}
val buildIspaBridge by tasks.registering(Exec::class) {
    dependsOn(compileIspaBridge)
    inputs.files("CMakeLists.txt", "parser_bridge.cpp", "../../parser/CMakeLists.txt")
    inputs.files(fileTree("../../parser/ispa") { include("**/*.h", "**/*.hpp", "**/*.cpp") })
    inputs.files(fileTree("../../parser/python") { include("**/*.h", "**/*.hpp", "**/*.cpp") })
    inputs.files(fileTree("../../parser/stdlibs") { include("CMakeLists.txt", "**/*.h", "**/*.hpp", "**/*.cpp") })
    outputs.file(bridgeExecutable)
    commandLine("cmake", "--build", bridgeBuild.get().asFile.absolutePath, "--config", "Release")
}
val stageIspaBridge by tasks.registering(Copy::class) {
    dependsOn(buildIspaBridge)
    from(bridgeExecutable)
    into(layout.buildDirectory.dir("generated/ispa-resources/native"))
    rename { bridgeFileName }
}
sourceSets.main { resources.srcDir(layout.buildDirectory.dir("generated/ispa-resources")) }
tasks.processResources { dependsOn(stageIspaBridge) }

// This plugin contributes no searchable settings pages.
tasks.named("buildSearchableOptions") { enabled = false }
