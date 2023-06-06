## Basic

ICPC Bangkok Regional에 참가하기 위해 수완나품 국제공항에 막 도착한 팀 레드시프트 일행은 눈을 믿을 수 없었다. 공항의 대형 스크린에 올해가 2562년이라고 적혀 있던 것이었다.

불교 국가인 태국은 불멸기원(佛滅紀元), 즉 석가모니가 열반한 해를 기준으로 연도를 세는 불기를 사용한다. 반면, 우리나라는 서기 연도를 사용하고 있다. 불기 연도가 주어질 때 이를 서기 연도로 바꿔 주는 프로그램을 작성하시오.

서기 연도를 알아보고 싶은 불기 연도 y가 주어진다. (1000 ≤ y ≤ 3000)

불기 연도를 서기 연도로 변환한 결과를 출력한다.

Translation:

Team Red-Shift couldn't believe their eyes when they just arrived at Suvarnabhumi Airport to participate in ICPC Bangkok Regional. In large screen of the airport, It was written that this year was the 2541 year.

Tailand, Buddhist country, uses Buddhist calendar year that starts at the year of Shakyamuni's nirvana. On the other hand, our country uses AD year. When the Buddhist calendar year is given, write the program that changes the Buddhist year to AD year.

Buddhist year is given. (1000 ≤ y ≤ 3000)

Prints out AD year which is AD version of the given Buddhist year.

## Points

Although it's very easy problem, we can check out the all data types of C language. We should keep in mind that every type of data has its own range and it's important that make it not to exceed it.

### 1. All data types in C

| Data Type | Size (bytes) | Range | Format Specifier |
|:---|:---|:---|:---| 
| short int |	2 |	-32,768 to 32,767 |	%hd |
| unsigned short int | 2 | 0 to 65,535 | %hu |
| unsigned int | 4 | 0 to 4,294,967,295 | %u |
| int | 4 | -2,147,483,648 to 2,147,483,647 | %d |
| long int | 4 | -2,147,483,648 to 2,147,483,647 | %ld |
| unsigned long int |	4 | 0 to 4,294,967,295 | %lu |
| long long int | 8 | -(2^63) to (2^63)-1 | %lld |
| unsigned long long int | 8 | 0 to 18,446,744,073,709,551,615 | %llu |
| signed char |	1 | -128 to 127 | %c |
| unsigned char |	1 |	0 to 255 | %c |
| float | 4 |	1.2E-38 to 3.4E+38 | %f |
| double | 8 | 1.7E-308 to 1.7E+308 | %lf |
| long double | 16 | 3.4E-4932 to 1.1E+4932	| %Lf |