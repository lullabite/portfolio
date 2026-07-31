class Solution(object):
    def minimumPushes(self, s):
        alp = {}
        ind = {}
        for i in s: # Считаем частоты
            if i in alp:
                alp[i] += 1
            else:
                alp[i] = 1
        alp = dict(sorted(alp.items(), key=lambda x: x[1], reverse=True)) # Сортируем по убыванию частоты
        keyboard = [[] for i in range(8)] # Распределяем по кнопкам
        while len(alp) > 0:
            for i in keyboard:
                if len(i) == min(len(j) for j in keyboard):
                    if len(alp) == 0:
                        break
                    else:
                        i.append(list(alp.keys())[0])
                        ind[list(alp.keys())[0]] = i.index(list(alp.keys())[0]) + 1
                        del alp[list(alp.keys())[0]]
        k = 0 # Считаем результат
        for i in s:
            for key, value in ind.items():
                if i == key:
                    k += value
        return k

if __name__ == "__main__":
    sol = Solution()
    test_string = 'xycdefghij'
    result = sol.minimumPushes(test_string)
    print(f"Input: {test_string}")
    print(f"Minimum pushes: {result}")
