# sapling

## Usage

**`sapling`**`spec_file`

With no options specified sapling only tells if a spec file is accepted by the
meta spec's language. A "Parse successful!" message will appear on success.
This message is printed to the standard error stream.

<br>

**`sapling`**`spec_file -fprint-lexer-output-only`

Prints the list of lexemes in the spec file that have been classified as
terminals. Here the numerical identifiers and names of the terminals are based
on sapling's internal representation of the meta spec symbols. This option only
runs the lexer so it is mutually exclusive with any options that invoke the
parser.

<br>

**`sapling`**`spec_file`**`[`**`-flog-state-stack`**`|`**`-flog-parse-tree-stack`**`]`**

Logs every state of the parser's state stack and parse tree node stack
respectively. Here the numerical identifiers of the states and the names of the nonterminals are based on sapling's internal representation of the meta spec
symbols.

<br>

**`sapling`**`spec_file`**`[`**`-fprint-terminals`**`|`**`-fprint-nonterminals`**`|`**`-fprint-productions`**`]`**

Prints the list of terminals, nonterminals and productions of the spec file
respectively. Here the numerical identifiers and names of the terminals and
nonterminals are taken from the input spec file.

<br>

**`sapling`**`spec_file`**`[`**`-fdump-parse-tree`**`|`**`-fdump-lexer-automaton`**`]`**

Dumps the parse tree graph and the lexer automaton graph in the DOT language.
The names of the non-lexeme nodes of the parse tree are based on sapling's
internal representation of the meta spec symbols. The lexer automaton terminal
names are taken from the input spec file.
