% function name should match file name. So, rename file while saving to disk.

function dump_matlab(file_name, buf)
  Path_str        = 'E:\TestData\';
  Underscore_str  = '_M';
  Txt_str         = '.txt';

  if isempty(buf)
    return;
  elseif isreal(buf)
    buf = buf';
    fptr = fopen([Path_str, file_name, Underscore_str, Txt_str], 'a');
    fprintf(fptr, '%10.10f\n', buf(:));
    fclose(fptr);
  else
    rebuf=real(buf);
    imbuf=imag(buf);
    rebuf = rebuf';
    imbuf = imbuf';
    fptr1 = fopen([Path_str, file_name, '_Real', Underscore_str, Txt_str], 'a');
    fptr2 = fopen([Path_str, file_name, '_Imag', Underscore_str, Txt_str], 'a');
    fprintf(fptr1, '%10.10f\n', rebuf(:));
    fprintf(fptr2, '%10.10f\n', imbuf(:));
    fclose(fptr1);
    fclose(fptr2);
  end
