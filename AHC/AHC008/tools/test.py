import concurrent.futures
import subprocess
import time

#コードをコンパイルする(pythonなどの場合不要)
subprocess.run(f"g++ -o double_saku3 double_saku3.cpp -std=c++17", shell=True)#要変更
print("input number test")
N = int(input())

start = time.time()

#パソコンのプロセス数
max_process = 2#要変更
proc_list = []
for i in range(N):
    S = str(i)
    while len(S) != 4:
        S = '0' + S
    #自分のコードを実行するためのコマンド
    proc = subprocess.Popen(f"cargo run --release --bin tester double_saku3 < in/{S}.txt > out/{S}.txt 2> score/{S}.txt", shell=True)#要変更
    proc_list.append(proc)
    if (i + 1) % max_process == 0 or (i + 1) == N:
        for subproc in proc_list:
            subproc.wait()
        proc_list = []

print("time: ", time.time() - start)

sum_score = 0
for i in range(N):
    S = str(i)
    while len(S) != 4:
        S = '0' + S
    with open(f"score/{S}.txt") as f:
        lines = f.readlines()
        score = int(lines[-1][8:-1])
        sum_score += score
print("average =", sum_score / N)