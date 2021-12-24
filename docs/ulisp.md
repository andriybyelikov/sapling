# uLisp

uLisp (micro Lisp) is the language used in the spec files to write the semantic
routines.

A semantic routine is made of a sequence of functions. Line comments begin with
`--`

```
<
    -- this is a line comment
    (fn_a arg1 arg2 ... argn) -- another line comment
    (fn_b)
    ...
    (fn_z)
>
```

---

## Flow control

`(if <cond> <runs when cond true> <runs when cond false>)`

```
(if 1
    (emit_line "true")
    (emit_line "false)
)
-- will emit "true"
```

If no code should run when condition evaluates then put `(nil)` in its place.

```
(if 0
    (emit_line "true")
    (nil) -- else do nothing
)
-- will do nothing
```

You can also place literals or call functions returning a value, the if will
evaluate to the corresponding value.

```
(emit_line (if 1 (lexeme "t_one" 0) "0")) -- emits lexeme of terminal t_one
```


## C standard library function wrappers

`(strequ <string> <string>)`

Returns 1 if the strings are equal, 0 if they are not.

`(strtol <string>)`

Converts strings to integers. Returns the same value as C's strtol called with
base 0.

## sapling specific

`lexeme <terminal node name: string> <occurrence: int>`

Returns the lexeme corresponding to the n-th occurrence of a terminal symbol
with the specified name.

## Binary

`emit_byte <int>`

Emits the value of the specified integer anded with 0xFF.

`emit_line <string>`

Emits the specified string, adding a trailing newline: LF on *nix systems and
CRLF on Windows systems.
