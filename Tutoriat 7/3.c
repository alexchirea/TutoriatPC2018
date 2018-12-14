bool izomorfe(char* X, char* Y) {
	int frX[256] = {0}, frY[256] = {0}, n = strlen(X);
    	for (int i = 0; i < n; ++i) {
        	if (frX[X[i]] != frY[Y[i]])
            	return false;
        	frX[X[i]] = i + 1;
        	frY[Y[i]] = i + 1;
    	}
    	return true;
}