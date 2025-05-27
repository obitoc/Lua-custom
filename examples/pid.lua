-- get pid
pid = cc.getpid()
print(pid)
-- get ppid
pidd = cc.getppid()
print(pidd)
-- get uid 
uid = cc.getuid()
print(uid)
-- kill
-- kill(pid: int,SIGNUM: int)
-- example
cc.kill(pid,9)
  
