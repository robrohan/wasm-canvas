# WASM to Canvas with Clang and no Emscripten

## Running

## Mac and Linux

You'll need `make` installed (Mac and Linux no problem see `brew` or `apt` or whatever). Just do:

```
make build
```

Then use your favorite mini http server and serve up the `public` directory (see `make start` for an example).

### Windows

On windows, you'll have to do something else, but you should be able to build with Visual Studio, install `clang` and port the `Makefile`.
