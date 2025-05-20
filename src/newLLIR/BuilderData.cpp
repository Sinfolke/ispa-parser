module LLIRBuilderData;
auto LLIR::BuilderData::initializationCheck() -> bool {
    return
        variable_count != nullptr &&
        isToken != nullptr &&
        addSpaceSkip != nullptr &&
        isFirst != nullptr &&
        tokensOnly != nullptr &&
        fullname != nullptr &&
        vars != nullptr &&
        key_vars != nullptr &&
        unnamed_datablock_units != nullptr &&
        tree != nullptr
    ;
}