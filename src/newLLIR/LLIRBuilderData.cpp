module LLIRBuilderData;
auto LLIRBuilderData::initializationCheck() -> bool {
    return
        variable_count != nullptr &&
        isToken != nullptr &&
        addSpaceSkip != nullptr &&
        isFirst != nullptr &&
        tokensOnly != nullptr &&
        fullname != nullptr &&
        members != nullptr &&
        vars != nullptr &&
        success_vars != nullptr &&
        key_vars != nullptr &&
        unnamed_datablock_units != nullptr &&
        tree != nullptr
    ;
}