/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var updateMatrix = function(matrix) {
    let dx = [1, -1, 0, 0];
    let dy = [0, 0, 1, -1];
    let q = new Array();
    let rows = matrix.length;
    let columns = matrix[0].length;
    let vis = new Array(rows);
    let ans = new Array(rows);
    for( let i = 0 ; i < rows ; i++ ) {
        vis[i] = new Array(columns).fill(0);
        ans[i] = new Array(columns).fill(0);
    }
    
    for( let i = 0 ; i < rows ; i++ ) {
        for( let j = 0 ; j < columns ; j++ ) {
            if( matrix[i][j] === 0 ) {
                vis[i][j] = 1;
                q.push(
                    {
                    x: i,
                    y: j,
                    cost: 0
                    }
                );
                
            }
        }
    }
    
    while(q.length) {
        let cur = q.shift();
        for( let i = 0 ; i < 4 ; i++ ) {
            let nx = cur.x + dx[i];
            let ny = cur.y + dy[i];
            let nxtCost = cur.cost + 1;
            if( nx >= 0 && nx < rows && ny >= 0 && ny < columns && vis[nx][ny] === 0 ) {
                q.push({
                    x: nx,
                    y: ny,
                    cost: nxtCost
                });
                vis[nx][ny] = 1;
                ans[nx][ny] = nxtCost;
            }
        }
    }
    return ans;
};
