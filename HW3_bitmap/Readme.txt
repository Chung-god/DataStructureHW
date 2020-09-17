bool getBit(long long num,int i){
    return((num & (1 << i)) != 0);
}

처음에 이렇게 잡았다가 1 을 입력하는데 0번째 bit 와 32번째 bit 가 1이 나왔다. 
왜 인지 생각해보다가 return 에 이는 1이 32bit 이기 때문에 발생한다는 걸 깨닫고 
다음과 같이 변경하니 문제가 없었다.

 bool getBit(long long num,int i){
    return((num & ((long long int)1 << i)) != 0);
} 