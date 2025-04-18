# javm-nx-poc

This is a Java ecosystem PoC for Nintendo Switch homebrew using libjavm VM library.

## **IMPORTANT!** this project is no longer continued.

It is a very basic example of how an ecosystem to run Java on Nintendo Switch (via homebrew) would work.

JAR files can directly be ran if the prepared files in `sd_out` are present in the SD card.

In order to use this project:

- Clone (recursively) this repo

- Build `javm` (just needs devkitA64). If the build process succeeds, `javm.nro` should have been copied to `sd_out`.

- Build the Java side of `nx` (needs maven, run `mvn package` in the directory)

- Build the `java-hello-world` example (same way ^)

- Copy manually the output JAR in `/target` to your SD card (anywhere, usually inside `/switch`) and the `sd_out` directory's contents to the root of your SD card.

- The example JAR should be launchable from hbmenu!

## Parts of the ecosystem

### - `javm`

The main executable which runs JARs (`javm.nro <jar-file> <arguments...>`)

Should be located at `/switch/javm/javm.nro`.

### - SD layout (special files)

- JPG icon for JAR files: `/switch/javm/jar-icon.jpg`

- File association file for launching JARs from hbmenu: `/config/nx-hbmenu/fileassoc/javm.cfg`

### - `nx`

Custom Java libraries, both a native C++ implementation and a stubbed JAR library for any projects using this ecosystem.

Sources are under `nx/native` for the C++/libjavm side and `nx/java` for the stubbed Java library. The Java side is compiled with maven.

## Example

The [hello world](java-hello-world) example is a Java version of the homebrew examples' hello world example, made to be compiled with maven.
