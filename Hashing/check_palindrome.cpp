int Solution::solve(string A) {
  int hashMap[26] = {0};
  for (char a: A)
    hashMap[a - 'a']++;
  int odd = 0;
  for (int a: hashMap)
    if (a % 2)
      odd++;
  if (odd > 1)
    return 0;
  return 1;
}
