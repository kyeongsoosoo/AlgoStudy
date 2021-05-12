 for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            if(maze[y][x] == 1){
                maze[y][x] = 0;
                bfs();
                maze[y][x] = 1;
                cout << len[N-1][M-1] << '\n';
                // min_len = min(min_len, len[N-1][M-1]);
                memset(len, -1, sizeof(len));
            }
        }
    }
    cout << min_len;