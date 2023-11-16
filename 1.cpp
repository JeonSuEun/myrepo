int offset[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	while (!is_empty()){
	position p = dequeue();
	for (int dir = 0; dir < 4; dir++) {
		for (int dist = 1; dist < N; dist++) {
			position q;
			q.x = p.x + dist * offset[dir][0];
			q.y = p.y + dist * offset[dir][1];
			if (q.x < 0 || q.x >= N || q.y < 0 || q.y >= N || maze[q.x][q.y] == 1)
				break;
			if (maze[q.x][q.y] == 0) {		
				enqueue(q);
				maze[q.x][q.y] = ? ;
			}
			//출구일때 ~
		}
	}
}
