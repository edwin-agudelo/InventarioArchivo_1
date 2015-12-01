CREATE TABLE [editorial] (
[edi_id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,
[edi_nombre] NVARCHAR(50)  UNIQUE NOT NULL,
[edi_reg] TIMESTAMP DEFAULT CURRENT_TIMESTAMP NULL
)

CREATE TABLE [divisiones] (
[div_id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,
[div_ruta] NVARCHAR(1000)  NOT NULL,
[div_nombre] NVARCHAR(50)  UNIQUE NOT NULL,
[div_elementos] NUMERIC DEFAULT '0' NULL,
[div_creado] DATE DEFAULT CURRENT_DATE NULL,
[div_descripcion] TEXT  NULL,
[div_estado] intEGER  NULL,
[div_padre] INTEGER  NULL
)

CREATE TABLE [libros] (
[lib_id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,
[lib_nombre] NVARCHAR(60)  NOT NULL,
[lib_edi_id] INTEGER DEFAULT '0' NULL,
[lib_autor] NVARCHAR(60)  NULL,
[lib_edicion] INTEGER DEFAULT '1' NULL,
[lib_anio] INTEGER DEFAULT '2000' NULL,
[lib_ruta] NVARCHAR(1000)  NOT NULL,
[lib_tamanio] FLOAT DEFAULT '0' NULL,
[lib_isbn] NVARCHAR(50)  NULL,
[lib_calificacion] INTEGER DEFAULT '1' NULL,
[lib_comprimido] INTEGER DEFAULT '0' NULL,
[lib_div_id] INTEGER  NOT NULL,
Foreign key(lib_div_id)
references divisiones(div_id)
)

CREATE TABLE [comentarios] (
[com_id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,
[com_lib_id] INTEGER  NOT NULL,
[com_fecha] daTE DEFAULT CURRENT_DATE NULL,
[com_comentario] teXT  NULL
)