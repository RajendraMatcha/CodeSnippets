clc; clear all; close all;

file1 = 'E:\TestData\data_msvc.txt';
file2 = 'E:\TestData\data_dmx.txt';

f1Id = fopen(file1);
f2Id = fopen(file2);

Ref = fscanf(f1Id, '%f');
x86 = fscanf(f2Id, '%f');

diff = (Ref-x86);
% diff = abs(Ref-x86).*100./max(max(abs(Ref),2.3283065059276353e-010));

figure;
subplot(311); plot(Ref,'r'); axis('tight');title('Ref');
subplot(312); plot(x86,'m'); axis('tight');title('x86');
subplot(313); plot(diff,'k'); axis('tight');title('Diff');
[diff, Idx] = max(diff);
fprintf('%f\n',diff);
fprintf('%d\n',Idx);
fclose(f1Id);
fclose(f2Id);
