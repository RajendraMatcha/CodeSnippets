# Multiprocessing using 'Pool'

import multiprocessing as mp

def sum_square(number):
  s = 0
  for ii in range(number):
    s += ii*ii
  return s

if __name__ == '__main__':
  total_cores = mp.cpu_count()
  p = mp.Pool(processes=total_cores)
  
  numbers = range(5)
  result = p.map(sum_square, numbers)
  
  p.close()
  p.join()
  
