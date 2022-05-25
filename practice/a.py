import random

def main():
    # #ランダムに並べられた重複のない整数の配列
    # array = [5, 4, 6, 2, 1, 9, 8, 3, 7, 10]
    # # ソート実行
    # sortedArray = sort(array)
    # # 結果出力
    # [print(i) for i in sortedArray]

    input_list = list(range(100))



    for i in range(10000):
        nxt_list = random.sample(input_list, len(input_list))
        sortedArray = sort(nxt_list)
        # print(*sortedArray)
        # print(*nxt_list)
        if sortedArray != input_list:
            exit()

    print('ok')


def sort(array):
    # 要素が一つの場合はソートの必要がないので、そのまま返却
    if len(array) == 1:
        return array

    # 配列の先頭を基準値とする
    pivot = array[0]

    # ここから記述

    # 左端or右端から探索するときの現在のindex
    index_left, index_right = 0, len(array) - 1

    # 値の交換が終わった後、基準値未満の最右端となるindex
    index_under_right = 0

    # 値の交換
    while index_left <= index_right: # 左側のindexが右側のindexを追い越すまで繰り返す

        # 左側、右側それぞれpivot以上、pivot未満であれば値を交換
        if array[index_left] >= pivot and array[index_right] < pivot:
            array[index_left], array[index_right] = array[index_right], array[index_left]
        
        # 左側の値がpivot未満のとき、index++ (基準値未満の最右端となるindexを記録しておく)
        if array[index_left] < pivot:
            index_under_right = index_left
            index_left += 1
            
        # 右側の値がpivot以上のとき、index--
        if array[index_right] >= pivot:
            index_right -= 1

    # 分割した配列それぞれをソートし、結合したものが答えとなる(再帰)
    return sort(array[:index_under_right+1]) + sort(array[index_under_right+1:])

    # ここまで記述

if __name__ == '__main__':
    main()