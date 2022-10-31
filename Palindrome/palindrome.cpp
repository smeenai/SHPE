#include <algorithm>
#include <iostream>
#include <string>

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

bool isPalindrome(const std::string& str) {
  // SOLUTION 1: see if the string is equal to itself when reversed.
  // `#if 0` and `#if 1` are preprocessor directives that are convenient for
  // enabling and disabling blocks of code. Change the 1 to 0 to switch to the
  // second solution.
#if 1
  return str == reverseString(str);
#else
  // SOLUTION 2: loop over the string and check corresponding characters.
  // size_t is just another integer type that's conventially used for lengths
  // and sizes.
  for (size_t i = 0, e = str.length(); i < e / 2; i++) {
    if (str[i] != str[e - 1 - i]) {
      // This is an early return: if a corresponding pair of characters (Nth
      // from the start and Nth from the end) aren't equal, we know it's not a
      // palindrome, and can just return false at that point. Some style guides
      // discourage them, but I think they make code cleaner as long as you keep
      // your functions short (which is good practice anyway).
      return false;
    }
  }

  // At this point we've looped over all corresponding character pairs and they
  // were all equal, so this must be a palindrome.
  return true;
#endif
}

bool isPalindromeWithoutSpaces(const std::string& str) {
#if 1
  // SOLUTION 1: remove spaces and then check if it's a palindrome.
  // You'll have to make a copy because `str` is `const std::string&`, so we
  // aren't allowed to modify it. You'll get a long compiler error if you try :)
  std::string strWithoutSpaces = str;
  // auto gives you the type of the right hand side automatically without
  // needing to spell it out. It's super useful for iterators, since those are a
  // pain to type out. auto drops const and references by default, so be careful
  // to avoid unnecessary copies though. E.g., `auto strCopy = str` would make a
  // copy even though `str` is `const std::string&`; `const auto& strRef = str`
  // would be needed to create another reference.
  auto endIt = std::remove(strWithoutSpaces.begin(), strWithoutSpaces.end(), ' ');
  strWithoutSpaces.erase(endIt, strWithoutSpaces.end());
  return isPalindrome(strWithoutSpaces);
#else
  // SOLUTION 2: loop and check corresponding character pairs as before, but
  // ignore spaces.
  // This is tricky to get right. I generally prefer simpler code (like the
  // first solution), and only reach for more complicated solutions in the cases
  // when the performance of a particular piece of code is known to be important
  // (e.g. because you profiled and found that it was a bottleneck).
  size_t left = 0;
  size_t right = str.length() - 1;
  while (left < right) {
    if (str[left] == ' ') {
      left++;
    } else if (str[right] == ' ') {
      right--;
    } else {
#if 1
      if (str[left] != str[right]) {
        return false;
      }
      left++;
      right--;
#else
      // Note that `left++` is a post-increment expression, i.e. it evaluates to
      // the value of `left` before the increment. There's also the pre-increment
      // version `++left`, which increments left and then evaluates to the new
      // value. Because these are expressions, we can use them directly like
      // below, although it reads less clearly that way IMO (but it's pretty
      // common to see). (We could also do the same above. It's not a problem in
      // this case, but just be careful about accidentally incrementing or
      // decrementing something twice.)
      // Note also that `#if 0` can be nested :)
      if (str[left++] != str[right--]) {
        return false;
      }
#endif
    }
  }

  return true;
#endif
}

int main() {
  std::string str1 = "a man a plan a canal panama";
  std::string str2 = "amanaplanacanalpanama";

  if (isPalindrome(str1)) {
    std::cout << str1 << " is a palindrome\n";
  } else {
    std::cout << str1 << " is not a palindrome\n";
  }

  if (isPalindrome(str2)) {
    std::cout << str2 << " is a palindrome\n";
  } else {
    std::cout << str2 << " is not a palindrome\n";
  }

  if (isPalindromeWithoutSpaces(str1)) {
    std::cout << str1 << " is a palindrome when spaces are removed\n";
  } else {
    std::cout << str1 << " is not a palindrome when spaces are removed\n";
  }
}
