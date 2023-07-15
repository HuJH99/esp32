idf_component_register(
                        SRCS
                        # "src.c"
                        "serial_dev.c"

                        INCLUDE_DIRS
                        # "include"
                        "."

                        REQUIRES
                        driver log

                        PRIV_REQUIRES
                        # component
                        )
