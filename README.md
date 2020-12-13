# sapling

A general-purpose compiler

## Dependencies

- [libsapling v0.4.0](https://github.com/andriybyelikov/libsapling/releases/tag/v0.4.0)

## Installation

Compile the library with ```make``` then run ```sudo make install``` on your
Linux/Unix system. This will install ```sapling``` and its man page.

## Specification

```
{terminals}
start -> {starting_symbol};
{nonterminals}
```

Terminal symbols prefixed with ```gobble__``` are not emitted from the lexer to
the parser.
