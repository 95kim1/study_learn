def solution(triangle):
    # 메모이제이션용 리스트
    triangle_mem = []
    answer = 0
    
    # 메모이제이션 시작
      # previous row에 접근하기 위해 index 이용
    for i in range(len(triangle)):
        triangle_mem.append([])
        for j in range(len(triangle[i])):
            temp = triangle[i][j]
        
            if i == 0:
                triangle_mem[-1].append(temp)
                continue
            
            # Not exsist: triangle_mem[i-1][j-1]
            if j == 0: 
                temp += triangle_mem[i-1][j]
            # Not exsist: triangle_mem[i-1][j]
            elif j == len(triangle_mem[i-1]): 
                temp += triangle_mem[i-1][j-1]
            # (중간)최댓값 구하기
            elif triangle_mem[i-1][j-1] > triangle_mem[i-1][j]:
                temp += triangle_mem[i-1][j-1]
            else:
                temp += triangle_mem[i-1][j]
            
            # 값 기록
            triangle_mem[-1].append(temp)
    
    # (최종)최댓값 구하기
    for elem in triangle_mem[-1]:
        if answer < elem:
            answer = elem
            
    return answer
