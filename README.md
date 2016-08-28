# Burrows-Wheeler-Transform-and-Suffix-Array

---

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

---

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

---

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

---

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

---

**suffix_array_long.cpp**

This file a more efficient version (O(nlogn)) way to construct suffix array, especially useful for long strings.

* Input: a string Text ending with a '$' symbol.
* Output: suffixArray(Text)

<em>**Example**</em>:

#### Input:
``` 
GAGAGAGA$
```
#### Output:
```
8 7 5 3 1 6 4 2 0
```

---

**suffix_array_matching.cpp**

Find the matching patterns in a string using suffix array.

* Input: The first line constains a string Text. The second line specifies an integer n. The last line gives a collection of n strings Patterns = {p1, ..., pn} seperated by spaces.
* Output: All starting positions (in any order) in Text where a pattern appears as a substring (using
0-based indexing as usual).

<em>**Example**</em>:

#### Input:
``` 
ATATATA
3
ATA C TATAT
```
#### Output:
```
4 2 0 1
```

