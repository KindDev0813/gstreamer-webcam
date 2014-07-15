/* Aravis - Digital camera library
 *
 * Copyright © 2009-2014 Emmanuel Pacaud
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Author: Emmanuel Pacaud <emmanuel@gnome.org>
 */

#ifndef ARV_CHUNK_PARSER_H
#define ARV_CHUNK_PARSER_H

#include <arvtypes.h>
#include <arvgc.h>

G_BEGIN_DECLS

#define ARV_TYPE_CHUNK_PARSER             (arv_chunk_parser_get_type ())
#define ARV_CHUNK_PARSER(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), ARV_TYPE_CHUNK_PARSER, ArvChunkParser))
#define ARV_CHUNK_PARSER_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), ARV_TYPE_CHUNK_PARSER, ArvChunkParserClass))
#define ARV_IS_CHUNK_PARSER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ARV_TYPE_CHUNK_PARSER))
#define ARV_IS_CHUNK_PARSER_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), ARV_TYPE_CHUNK_PARSER))
#define ARV_CHUNK_PARSER_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), ARV_TYPE_CHUNK_PARSER, ArvChunkParserClass))

typedef struct _ArvChunkParserPrivate ArvChunkParserPrivate;
typedef struct _ArvChunkParserClass ArvChunkParserClass;

struct _ArvChunkParser {
	GObject	object;

	ArvChunkParserPrivate *priv;
};

struct _ArvChunkParserClass {
	GObjectClass parent_class;
};

GType arv_chunk_parser_get_type (void);

ArvChunkParser *	arv_chunk_parser_new 				(ArvGc *genicam);
const char *		arv_chunk_parser_get_string_feature_value	(ArvChunkParser *parser, ArvBuffer *buffer, const char *feature);
gint64			arv_chunk_parser_get_integer_feature_value	(ArvChunkParser *parser, ArvBuffer *buffer, const char *feature); 
double			arv_chunk_parser_get_float_feature_value	(ArvChunkParser *parser, ArvBuffer *buffer, const char *feature);

G_END_DECLS

#endif
