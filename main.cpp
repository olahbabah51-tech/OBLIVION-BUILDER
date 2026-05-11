name: Build Android SO
on: [push]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3

      - name: Set up NDK
        uses: nttld/setup-ndk@v1
        with:
          ndk-version: r21e

      - name: Compile SO
        run: |
          $ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/armv7a-linux-androideabi21-clang++ \
          -shared -fPIC main.cpp -o libOBLIVION.so

      - name: Upload Artifact
        uses: actions/upload-artifact@v3
        with:
          name: OBLIVION_LIBRARY
          path: libOBLIVION.so
