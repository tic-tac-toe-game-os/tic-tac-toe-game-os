char* clearMsg(char* msg) {
    int i = 0;
	int j = 0;
	
	while(msg[i] != '\0') {
		if(msg[i] != ':' && msg[i] != '#') {
			msg[j] = msg[i];
			j++;
		}
		i++;
	}
	msg[j] = '\0';
	
	return msg;
}