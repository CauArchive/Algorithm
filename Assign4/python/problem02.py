import random


def generate_matrix(row, column):
    matrix = [[0 for i in range(column)] for j in range(row)]
    for i in range(row):
        for j in range(column):
            matrix[i][j] = random.randrange(1, 100)
    return matrix


def print_matrix(input_matrix):
    row = len(input_matrix)
    column = len(input_matrix[0])
    print("output of matrix", row, " by ", column)
    for i in range(row):
        for j in range(column):
            print(input_matrix[i][j], end=" ")
        print('')
    print('')


def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0 for i in range(n+1)] for j in range(n+1)]
    s = [[0 for i in range(n+1)] for j in range(n+1)]

    for l in range(2, n+1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            m[i][j] = float("inf")
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

    return (m, s)


def opt_chain_order(s, i, j):
    if i == j:
        print("A", end="")
        return
    k = s[i][j]
    print("(", end="")
    opt_chain_order(s, i, k)
    opt_chain_order(s, k+1, j)
    print(")", end="")


def matrix_multi(first, second):
    if len(first[0]) != len(second):
        print("incompatible dimensions")
        return
    result = [[0 for i in range(len(second[0]))] for j in range(len(first))]
    for i in range(0, len(first)):
        for j in range(0, len(second[0])):
            for k in range(0, len(first[0])):
                result[i][j] += first[i][k] * second[k][j]
    return result


p = [5, 3, 7, 10]
n = len(p) - 1
matrix_5x3 = generate_matrix(5, 3)
matrix_3x7 = generate_matrix(3, 7)
matrix_7x10 = generate_matrix(7, 10)

m, s = matrix_chain_order(p)
print(m)
print(s)

print("optimal chain order is ", end=" ")
opt_chain_order(s, 1, n)
print('')
print('')
print("minimal number of computation is ", m[1][n])
print('')
c = matrix_multi(matrix_3x7, matrix_7x10)
d = matrix_multi(matrix_5x3, c)
print_matrix(d)
