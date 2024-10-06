TOKEN(END) {
    if (*in == ';' or *in == '\n')
        TOKEN_SUCCESS(in, in + 1, END);
    return {};
}
TOKEN(STRICT_END) {
    if (*in == ';')
        TOKEN_SUCCESS(in, in + 1, STRICT_END);
    return {};
}
TOKEN(NEWLINE) {
    if (*in == '\n')
        TOKEN_SUCCESS(in, in + 1, NEWLINE);
    return {};
}