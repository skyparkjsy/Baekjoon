
// b1260. DFS와 BFS

/* 포인트 */
// 두 정점 사이에 여러 개의 간선 있을 수 있음 (방문 표시 체크로 해결?)
// 간선: 양방향 (하나의 연결 받아서, 두 정점 배열 모두에 표시)
// (풀다가 추가) dfs, bfs 둘 다 수행해야 되니깐, dfs 세팅 후 배열 세팅 및 초기화 잘 하기 

/* 구현 방법 
	2차원 배열: [n][0]에 연결된 정점의 개수 체크
*/

/* 타임라인 */
// 15:07 입력 받아서 arr배열 업데이트 체크 완료
// 16:34 테스트 케이스 더 모아서 체크했음 -> okay 근데 제출하면 5%에서 틀림
