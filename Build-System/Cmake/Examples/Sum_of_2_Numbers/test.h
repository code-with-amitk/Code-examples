int sum(int a,int b){
	int VAR = 0;
#if defined(WIN32)
	VAR=4;
#else
	VAR=400;
#endif

  return a+b + VAR;
}
