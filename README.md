# sapling

A general-purpose compiler (WIP)

Currently it has the analytic power of an Simple LR parser, while its humble
synthetic power is provided by a small Lisp-like language called uLisp or micro
Lisp. *sapling* accepts a composite source file, written in fragments of
multiple arbitrary languages, with each fragment either being written in one
language and translated to another or being written in the highest of a stack
of languages and being transitively translated into each successive language in
the stack until finally being translated to the lowest one in the stack.

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

## uLisp parse trees visualization

From the `build` folder run `./sapling-backup -m ../spec/sample/6502_to_bin -dump-ulisp-parse-trees | sh ../tools/viz_ulisp_parse_trees`
