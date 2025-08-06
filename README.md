# tree_map

## Build

```sh
mkdir -p build
```

```sh
cd build
cmake -S ..
make
```

## Install


```sh
make install
```

## Test

```sh
cmake -S . -B build
cmake --build build
```
```sh
cd build && ctest
```


