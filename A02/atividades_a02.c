
// Atividade 1
int i, j, k
for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
        r[i][j] = 0;
        for(k = 0; k < n; k++){
            r[i][j] += a[i][k] * b[k][j];
        }
    }
}

//---------------------------------------------

// Atividade 2
int i, j, k, s;
for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
        for(k = 1; k < j; k++){
           s = 1;
        }
    }
}

//---------------------------------------------

// Atividade 3
int i, j, s;
s = 0;
for(i = 1; i < n - 1; i++){
    for(j = 1; j < 2 * n; j++){
            s = s + 1;
    }
}
