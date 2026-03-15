# generates the ODB files that bridge the cpp-class and the db
function(odb_compile TARGET_NAME HEADER_FILE OUTPUT_DIR)
    # Get the filename without extension (e.g., "Character")
    get_filename_component(HEADER_NAME ${HEADER_FILE} NAME_WE)
    
    # Define the paths of the files ODB will generate
    set(GEN_CXX "${OUTPUT_DIR}/${HEADER_NAME}-odb.cxx")
    set(GEN_HXX "${OUTPUT_DIR}/${HEADER_NAME}-odb.hxx")
    set(GEN_IXX "${OUTPUT_DIR}/${HEADER_NAME}-odb.ixx")
    set(GEN_SQL "${OUTPUT_DIR}/${HEADER_NAME}.sql")

    # The actual ODB compilation command
    add_custom_command(
        OUTPUT "${GEN_CXX}" "${GEN_HXX}" "${GEN_IXX}" "${GEN_SQL}"
        COMMAND odb
        ARGS -d sqlite
             --std c++20
             --generate-query
             --generate-schema
             --output-dir "${OUTPUT_DIR}"
             -I "${CMAKE_CURRENT_SOURCE_DIR}/Code/Include"
             "${HEADER_FILE}"
        DEPENDS "${HEADER_FILE}"
        COMMENT "Generating ODB files for ${HEADER_NAME}..."
        VERBATIM
    )

    # Add the generated .cxx file to the target so it gets compiled
    target_sources(${TARGET_NAME} PRIVATE "${GEN_CXX}")
    
    # Ensure the target can find the generated headers
    target_include_directories(${TARGET_NAME} PRIVATE "${OUTPUT_DIR}")
endfunction()