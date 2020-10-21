class Solution {
public:
    double ed(int x1, int y1, int x2, int y2){
        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        double d[51][51][51][51];
        sort(towers.begin(), towers.end());
        for(int i = 0; i < 51; i++){
            for(int j = 0; j < 51; j++){
                for(int k = 0; k < 51; k++){
                    for(int l = 0; l < 51; l++){
                        d[i][j][k][l] = -1;
                    }
                }
            }
        }

        for(int i = 0; i < towers.size(); i++){
            int x1 = towers[i][0];
            int y1 = towers[i][1];
            d[x1][y1][x1][y1] = 0;
            for(int j = i+1; j < towers.size(); j++){
                int x2 = towers[j][0];
                int y2 = towers[j][1];
                double dist = ed(x1, y1, x2, y2);
                d[x1][y1][x2][y2] = dist;
                d[x2][y2][x1][y1] = dist;
            }
        }
        int ansX = 0, ansY = 0;
        int maxQuality = 0;
        for(int i = 0; i < towers.size(); i++){
            int x = towers[i][0];
            int y = towers[i][1];
            // cout << x << " " << y << " " << endl;
            int quality = 0;
            for(int j = 0; j < towers.size(); j++){
                int x1 = towers[j][0];
                int y1 = towers[j][1];
                if(d[x][y][x1][y1] <= radius){
                    quality += floor(towers[j][2]/(1 + d[x][y][x1][y1]));
                }
            }
            // cout << quality << endl;
            if(quality > maxQuality){
                maxQuality = quality;
                ansX = x;
                ansY = y;
            }
        }
        return vector<int>{ansX, ansY};
    }
};