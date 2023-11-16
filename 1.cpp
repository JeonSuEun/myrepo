while (!is_empty){
	position p = dequeue();
	for (int dir = 0; dir < 4; dir++) {
		for (int dist = 1; dist < N; dist++) {
			int xx = p.x + dist * offset[dir][0];
			int yy = p.y + dist * offset[dir][1];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N || maze[xx][yy] == 1)
				break;
			if (maze[xx][yy] == 0) {
				position q;
				q.x = xx, q.y == y;
				enqueue(q);
				maze[xx][yy] = ? ;
			}
		}
	}
}