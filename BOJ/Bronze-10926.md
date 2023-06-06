## Basic

준하는 사이트에 회원가입을 하다가 joonas라는 아이디가 이미 존재하는 것을 보고 놀랐다. 준하는 놀람을 ??!로 표현한다. 준하가 가입하려고 하는 사이트에 이미 존재하는 아이디가 주어졌을 때, 놀람을 표현하는 프로그램을 작성하시오.

첫째 줄에 준하가 가입하려고 하는 사이트에 이미 존재하는 아이디가 주어진다. 아이디는 알파벳 소문자로만 이루어져 있으며, 길이는 50자를 넘지 않는다.

첫째 줄에 준하의 놀람을 출력한다. 놀람은 아이디 뒤에 ??!를 붙여서 나타낸다.

Translation:

Junha was surprised to see that id "joonas" already exists when he signs up for a website. He express his surprise using ??!. Write a program that express a surprise when existing id is given in the website where Junha's gonna sign up.

In first line, existing id is given for the website. Id only consists of lower case of the letter of the alphabet and its length doesn't exceed 50 characters.

Prints a Junha's surprise at the first line. The surprise expressed as ??! after a given id.

## Points

### 1. Trigraphs

In C programming language, there is Trigraph (Sequence) which is a complementary thing because of some language which doesn't accept all character set that C provides. There are 9 Trigraphs which are shown below as a table.

| Trigraph | Shown as |
|:---:|:---:|
| ??= | # |
| ??( | [ |
| ??< | { |
| ??/ | \ |
| ??) | ] |
| ??> | } |
| ??' | ^ |
| ??! | \| |
| ??- | ~ |

For example, next code prints out "#".

```c
printf("??=");
```