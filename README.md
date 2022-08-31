# 2022-Algorithm_Study
알고리즘 스터디


# 2022-Algorithm-Study

> 코딩 테스트 준비를 위한 스터디입니다. 

- 기간: 2022년 9월~
- 참고 사이트: [프로그래머스](https://school.programmers.co.kr/learn/challenges), [백준]( https://solved.ac/ ), [LeetCode]( https://leetcode.com/ )
- 언어: 파이썬,C++ 등 (자율)

## 스터디 규칙 

- 못풀어도 좋습니다. 나 이거 쉽게풀었어 자랑하는게 목적이아니라 현재부족하다면 개인의 실력을 스터디를 통해 합격권까지 이끌어내는게 목표입니다.
무작정 코드작성 -> 제출 -> 수정 -> 제출 방식보다는 쉬운문제더라도 내가 testcase 도 만들어보고 코너케이스도만들어보면서 실력을 키워나가는게 목표입니다
실제로 testcase 적게주는 회사들도있기때문에 
내가 생각한풀이에대해 검증하는 능력이정말 중요하다고 생각되어서 해당방식으로 진행하려고합니다.  

1. 먼저 난이도를 선택 (ex 백준 : Golv 4 or LeetCode medium , Programmers Lv 3 ) 
2. 팀원들한테 추천받거나 같은문제를풀면 더욱좋고 ( 추천시 백준기준 문제푼 사람수어느정도 있는 문제를 추천부탁드립니다 )  개인이선택 태그나 유형은 절대 보지말것  대신에 ( 그리디, 문자열, DFS, BFS, DP, TREE, 누적합, 백트랙킹 ,이분탐색, 완전탐색, 구현 의 범위에서는 벗어나지않았으면 좋겠습니다. segment tree 나 다른 고급알고리즘은 코딩테스트 기준에 오버스펙이라고 생각됩니다. 원하시면 추천받아서 푸셔도 상관x 단 피드백은 못해줄수도 있습니다 )
3. 각자 정한 시간 0~ 최대 90~120분사이정하고 문제링크와 자기가 했던 생각, 방향들을 정리해서 제출 ( 시간복잡도,공간복잡도 필수 )
4. 그러면 팀원이 문제와 풀이를 보고 피드백 




#### 문제 풀이

1. 소스파일 + pdf(자율)
2. 반드시 코드 리뷰 후에 main branch로 merge.
3. 기본적으로 올릴 때는 각자 이름으로 된 branch에 올림.


#### 설명 방식

1. 적용 알고리즘 개념 간단하게 주석달고 
2. 문제 풀이를 위한 접근 방식(or 개념) 설명. 아이패드를 통해 노터빌리티등으로 설명해도좋음 (pdf파일로 업로드,원본 + 정리한파일(알아볼수있게 정리해서 올려주셨으면 좋겠습니다.)) 
3. 기본 코드에 대한 간단한 설명
4. 막혔다면 막힌 코드또한 주석으로 첨부 -> 왜 막혔는지 간단하게 설명
5. 시간 복잡도, 공간 복잡도 계산 => 문제풀이 이전에 시간복잡도와 공간복잡도 예측후에 들어가기
6. 사용 라이브러리 정리
7. 기타(문제 풀이에 어려웠던 점, 구현하고자 했는데 실패한 방식) := 간단한 후기



## PR 규칙 및 Commit Message 규칙
mac os 기준

1. 초대받고 수락
2. 해당 원본 repository를 자신의 github 에 fork 한다 (fork 후 생성되었는지 확인)
3. 터미널에서 cd 로컬저장소(git clone 으로 다운받은)로 디렉토리 이동후 -> git remote add center[짓고싶은별명으로 지으세요] https://github.com/wjs2063/2022-Algorithm_Study.git
4. 여기까지 완료되었다면 git remote -v 를 해보면 아마 4줄이 뜨게된다. ( 내가지은 별명 2줄 -> 원본) + (fork 한 내 깃허브 폴더 아마 origin 으로 되어있을?것으로 예상)

- 이제 branch 생성 작업

1. git branch 를 해보면 *main 한개만 뜬다. 
2. git checkout -b wjs2063 [ 자신의 branch 명] 적어주기  
3. git branch 해보면 *wjs2063과 main 이렇게 2개가 뜨게된다  
완료 

- 해당 문제풀이 후에 소스코드와 pdf 파일 을리기 

git add .  
git status (로 확인) 
git commit -m " 커밋 메세지(규칙에 따라서 ) "  
git push origin [나의 branch 명] 으로 푸쉬  

- push 완료  


(서로의 코드나 생각들을 피드백한다음 고친후에 꼭 pull request 요청을 해주자 그러면 팀장이 main 저장소에 merge 할것) 

이제 실제 내 github 웹사이트 repository 로 가보면 compare pull -request 가 생성되었다  

팀장이 main에 merge 를 하고나면 

git pull center (자신이 지은 메인저장소 별칭) 으로 변경된 정보를 가져온다 

그리고 git branch -d wjs2063 내가 진행한 branch 삭제  

그리고 앞서설명한 branch 생성 삭제 무한반복  


#### Pull Request

- [Programmers-폴더명] 이름

- [Baekjoon-폴더명] 이름

#### Commit Message

- [Programmers-문제번호] 문제명

- [Baekjoon-문제번호] 문제명

- [LeetCode-문제번호] 문제명

## 파일 및 폴더 구조

#### 프로그래머스

- Programmers/팀원이름(ex jaehyeon)/폴더명/문제명.py
- Programmers/팀원이름/폴더명/문제명.py
- Programmers/팀원이름/폴더명/문제명.py

#### 백준

- Baekjoon/팀원이름(ex jaehyeon)/폴더명/문제번호_문제명.py
- Baekjoon/팀원이름(ex jaehyeon)/폴더명/문제번호_문제명.py
- Baekjoon/팀원이름/폴더명/문제번호_문제명.py

#### 리트코드 
- LeetCode/팀원이름/폴더명/문제번호_문제명.py
- LeetCode/팀원이름/폴더명/문제번호_문제명.py
- LeetCode/팀원이름/폴더명/문제번호_문제명.py
