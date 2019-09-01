// [Easy]
// This problem was asked by Google.
// 
// The edit distance between two strings refers to the minimum number of character insertions, 
// deletions, and substitutions required to change one string to the other. 
// For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, 
// substitute the “e” for “i”, and append a “g”.
// 
// Given two strings, compute the edit distance between them.


// ed[m+1][n+1],
// ed[i][j] => minimum edit distance str1[0..i-1] str2[0..j-1]
// ed[i][j] = i ==0 => j, j == 0=> i
//             = str1[i-1] == str2[j-1], ed[i-1[j-1]
//             = else min(ed[i-1][j], // exclude j)
//                         ed[i][j-1], ed[i-1][j-1]) + 1


// TODO: can skip