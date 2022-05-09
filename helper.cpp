// validasi jangan input karakter \ / : * ? " < > |
int validateChar(char ektensiFileTemp){
	if(ektensiFileTemp == '\\' || ektensiFileTemp == '/' || ektensiFileTemp == ':' || ektensiFileTemp == '*' || ektensiFileTemp == '?' || ektensiFileTemp == '"' || ektensiFileTemp == '<' || ektensiFileTemp == '>' || ektensiFileTemp == '|'){ 
		return 1;
	} else {
		return 0;
	}
}