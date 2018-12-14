int compress(char* sir, int lungime) {
	int i, k, rezultat = 0;
	for (i=0; i<lungime-1; i++) {
    	k = 0;
    	while (sir[i] == sir[i+1] && i<lungime-1) {
        	k++;
        	i++;
    	}
    	rezultat++;
    	if (k > 1) {
        	int nrCifre = 0;
        	while (k) {
            	nrCifre++;
            	k/=10;
        	}
        	rezultat+=nrCifre;
    	}
	}
	if (sir[lungime-1]!=sir[lungime-2])
    	rezultat++;
	return rezultat;
}