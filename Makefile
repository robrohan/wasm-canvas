
CC=clang

clean:
	rm -f public/draw.wasm

build:
# Set Some initial memory
# -Wl,--initial-memory=$$(( 8 * 65536 ))

# If you want to export all the functions without having to mark
# things as EXPORT
# -Wl,--export-alle

	$(CC) \
		--target=wasm32 \
		-std=c99 \
		-Wall \
		-g \
		-O3 -flto \
		-nostdlib \
		-Wl,--export-dynamic \
		-Wl,--no-entry \
		-Wl,--lto-O3 \
		-Wl,-z,stack-size=$$(( 8 * 1024 * 1024 )) \
		-o public/draw.wasm \
		src/walloc.c src/maths.c src/graphics.c

start: clean build
# You probably wont have this: https://github.com/robrohan/busboy
# But anything like it will do. e.g. python3 -m http.server
	busboy --root=public

serve: clean build
	cd public; python3 -m http.server
