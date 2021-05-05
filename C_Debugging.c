

// Tracing while debugging
printf("DEBUG ------------------- %s, %s, %d\n", __FILE__, __FUNCTION__, __LINE__);

// Dumping
if (1)
{
	FILE *fp = NULL;
	fopen_s(&fp, "E:\\TestData\\data.txt", "a");
	for (int dd = 0; dd < fftSize / 2 + 1; dd++)
	{
		fprintf(fp, "%10.20f \n", fftInOutBuffer[dd].to_float());
		// fprintf(fp, "%10.20f \n", F_AFLOAT_TO_DOUBLE(pallStateL[ii]));
	}
	fclose(fp);
}

// Faster way, but might be unsafe.
if (1)
{
	static FILE *fp = NULL;
	if(NULL == fp)
		fopen_s(&fp, "E:\\TestData\\before.txt", "w");
	for (int dd = 0; dd < fftSize / 2 + 1; dd++)
	{
		fprintf(fp, "%10.20f \n", fftInOutBuffer[dd].to_float());
		// fprintf(fp, "%10.20f \n", F_AFLOAT_TO_DOUBLE(pallStateL[ii]));
	}
	//fclose(fp);
}


// Loop back
if (1)
{
	static FILE *fp = NULL;
	float temp;
	if(NULL == fp)
	fopen_s(&fp, "E:\\TestData\\boneIn_ref.txt", "r");
	for (int dd = 0; dd < 256; dd++)
	{
		fscanf_s(fp, "%f \n", &temp);
		pArgsVtFusion.pBoneCondTime[dd] = temp;
	}
	//fclose(fp);
}
