# Regular Expression
    - powerful mean for querying texual data sets - interesting information is found with the help of regular expression `patterns`
## REgular Expression dialetcs
    - BRE(Basic)
    - ERE(Extended)
      - add some features and changes to BRE and supported bu `egrep`
    - Perl regular Expression
      - add lot of features to ERE and supported by Perl
      - `pcregrep` tool to check  
## Outline
  - atoms
  - repetition operators
  - concatenation
  - alternation
  - ()

## How regular expression built
    Atom (Reetition operators) -> Piece (Concatenation)-> Branch (The | operators)-> Regular Expression
```
  `a` match `car`
  `\?` match `what?`
  `\$` match `what$`
  `\^` match `2^3`
  `\\` match a\b
  `.` match any character
  `\.` match only .
```
# atom
```
  [list] matches any character in the list
  [^list] matches any character not in the list
  [a-z0-9] matches anything within the range
  [^0-9.]
```
# Matching single characters
## inside [] special characters(? or .) treated as regular character
```
  [:C:] maybe used inside []
  [:alpha:]
  [:digit:]
  [:alnum:]
  [:punc:]
  [:space:]

  [[:alpha:]01] -> matches a letter (both lower and upper case), or digit 0 or 1
  [[:alnum:]_,@]
  [ABC[:punc:]] # matches a letter A, B or C, or any punctuation character like ! @ # ( ] | _ etc.
  [^[:print:]] # prints anything that's not printable character
  [[:cntrl:][:blank:]]
  [^[:space:]]
  [ABC[:punct:]]
  \w  -> [[:alnum:]_] -> [0-9A-Za-z_]
  \W  -> [^[:alnum:]_]
  $   -> end of a string
  \b  -> word boundary(empty string at the begging or end of word)
  \B  -> empty string that's not start or end of a word
  ^   -> beginning of a string  
  $   -> end of a string
```

# pieces
```
  X? -> single or zero
  X* -> zero or more
  X+ -> one or more

  X{n} ->  matches n consecutive occurrences of strings matched by atom X
  X{n,} -> at least n
  X{n,m} -> at least n & at most m
```
# branches
```
  ^[0-9]+$
  ^y?[0-9]+$
  john\b
  ^[0-9]{3}[A-Za-z]{3}$

  |

  ^We like|apples 
  ^[0-9]{3}[A-Za-z]{3}$|^[A-Za-z]{3}[0-9]{3}$
  ^([0-9]{1,3}\.){3}[0-9]{1,3}$
  ^(We like (apples|bananas))?$

  sshd\[[0-9]+\]: Connection from [0-9.]+$
  sshd\[[0-9]+\]: Connection from ([0-9]{1,3}\.){3}[0-9]{1,3}$
  sshd\[[0-9]+\]: Failed .+ for \w+ from [0-9.]+ port [0-9]+ ssh2$

  ^[A-Za-z][A-Za-z0-9-]*[A-Za-z0-9]$
  ^([A-Za-z]|[A-Za-z][A-Za-z0-9-]*[A-Za-z0-9])$

```

 `use egrep tool to check`

