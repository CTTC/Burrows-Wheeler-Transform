# Burrows-Wheeler-Transform

**bwt.cpp**

This file is used to generate the Burrows-Wheeler transform of a string

* Input: a string text ending with a '$' symbol
* Output: BWT(text)


<em>**Example**</em>:

#### Input:
``` 
ACACACAC$
```
#### Output:
```
CCCC$AAAA
```

**bwtinverse.cpp**
This file is used to reconstruct a string from its Burrows-Wheeler transform

* Input: a string Transform with a single '$' symbol
* Output: the string Text such that BWT(Text) = Transform
 
<em>**Example**</em>:

#### Input:
``` 
AGGGAA$
```
#### Output:
```
GAGAGA$
```

**bwmatching.cpp**

This file is used to find the number of occurences of a pattern in a string text.

* Input: a string BWT(Text), followed by an integer n and a collection of n strings Patterns = {p1,..., pn}
* Output: a list of integers, where the i-th integer corresponds to the number of substring matches of the i-th member of Patterns in Text.

<em>**Example**</em>:

#### Input:
``` 
ATT$AA
2
ATA A
```
#### Output:
```
2 3
```

**suffix_array.cpp**

This file is used to construct the suffix array of a string.

* Input: a string Text ending with a '$' symbol.
* Output: suffixArray(Text)

<em>**Example**</em>:

#### Input:
``` 
AACGATAGCGGTAGA$
```
#### Output:
```
15 14 0 1 12 6 4 2 8 13 3 7 9 10 11 5
```
