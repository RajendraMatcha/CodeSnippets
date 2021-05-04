% Read data from Q15 PCM file.
clc; clear all; close all;

file_name = 'E:\TestData\dump.pcm';
fId = fopen(file_name);
if fId == -1
    error 'error opening input file';
end

data = fread(fId,'int16');
fclose(fId);

data1 = data / pow2(15);
figure; plot(data1); axis('tight');title('dump (PCM Q15)');
