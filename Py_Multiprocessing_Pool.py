# Multiprocessing using 'Pool'
# Using multiprocessing's pool, we can split the work and dispatch to 
# multiple CPUs that execute in parallel.

# However, using pool, we cannot dispatch to CPUs across multiple machines.
# For dispatching across multiple machines, try 'Ray' or 'Dask' or Jenkins?

import multiprocessing as mp

def sum_square(number):
  s = 0
  for ii in range(number):
    s += ii*ii
  return s

def main():
  total_cores = mp.cpu_count()
  p = mp.Pool(processes=total_cores)
  
  numbers = range(5)
  result = p.map(sum_square, numbers)
  
  p.close()
  p.join()


if __name__ == '__main__':
	main()
  
