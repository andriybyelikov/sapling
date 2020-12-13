# sapling

A general-purpose compiler

## Installation

Compile the library with ```make``` then run ```sudo make install``` on your
Linux/Unix system.

## Specification

```
{terminals}
start -> {starting_symbol};
{nonterminals}
```

Terminal symbols prefixed with ```gobble__``` are not emitted from the lexer to
the parser.
