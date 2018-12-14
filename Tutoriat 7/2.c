bool rotire(char* X, char* Y) {
	int nrMaxim = strlen(X);
	if (strlen(X) != strlen(Y))
    	return false;
	if (strcmp(X,Y) == 0) return true;
	while (nrMaxim-1) {
    	nrMaxim--;
    	char c = X[0];
    	int i;
    	for (i=0; i<strlen(X)-1; i++)
        	X[i] = X[i+1];
    	X[strlen(X)-1]=c;
    	if (strcmp(X,Y) == 0) return true;
	}
	return false;
}