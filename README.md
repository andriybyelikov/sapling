# sapling

A general-purpose compiler

## Dependencies

[libsapling](https://github.com/andriybyelikov/libsapling)

## Building from source and installing

Using GNU Autotools.

```
$ autoreconf --install
$ mkdir build
$ cd build
$ ../configure
$ make
$ sudo make install
```

## ![Arch Linux logo](https://raw.githubusercontent.com/unixporn/distro-icons/71c205b588a9ea021705867ebfccbd859a196192/SVG/arch.svg) Arch Linux packages

[Link to repository with PKGBUILD scripts](https://github.com/andriybyelikov/archlinux-sapling-packages)

---

## Specification

```
{terminals}

start -> {starting_symbol};
{nonterminals}
```

Terminal symbols prefixed with ```t_gobble__``` are not emitted from the lexer
to the parser.
