/* ---傳回四個整數中的最大值 ---*/
int max4(int w, int x, int y, int z) {
    return (maxof(maxof(w, x), maxof(y, z)));
}
